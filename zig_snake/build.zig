const std = @import("std");
const rl = @import("raylib-zig/build.zig");

pub fn build(b: *std.Build) !void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});
    var raylib = rl.getModule(b, "raylib-zig");
    var raylib_math = rl.math.getModule(b, "raylib-zig");
    //web exports are completely separate
    if (target.getOsTag() == .emscripten) {
        const exe_lib = rl.compileForEmscripten(b, "zig_snake", "src/main.zig", target, optimize);
        exe_lib.addModule("raylib", raylib);
        exe_lib.addModule("raylib-math", raylib_math);
        const raylib_artifact = rl.getArtifact(b, target, optimize);
        // Note that raylib itself is not actually added to the exe_lib output file, so it also needs to be linked with emscripten.
        exe_lib.linkLibrary(raylib_artifact);
        const link_step = try rl.linkWithEmscripten(b, &[_]*std.Build.Step.Compile{ exe_lib, raylib_artifact });
        b.getInstallStep().dependOn(&link_step.step);
        const run_step = try rl.emscriptenRunStep(b);
        run_step.step.dependOn(&link_step.step);
        const run_option = b.step("run", "Run zig_snake");
        run_option.dependOn(&run_step.step);
        return;
    }

    const exe = b.addExecutable(.{ .name = "zig_snake", .root_source_file = .{ .path = "src/main.zig" }, .optimize = optimize, .target = target });

    rl.link(b, exe, target, optimize);
    exe.addModule("raylib", raylib);
    exe.addModule("raylib-math", raylib_math);
    
    exe.addIncludePath(std.Build.LazyPath { .path = "src" });
    exe.addCSourceFile(.{ .file = .{ .path = "src/bindings.cpp" }, .flags = &.{"-std=c++11"} });

    const dir = try std.fs.cwd().openIterableDir("../", .{});
    var iterator = dir.iterate();
    var slices: [2] []const u8 = undefined;
    slices[0] = "../";
    const allocator = std.heap.page_allocator;

    while (try iterator.next()) |path| {
        if (std.mem.endsWith(u8 , path.name, ".cpp") and 
            !std.mem.eql(u8, path.name, "main.cpp"))
        {
            slices[1] = path.name;
            var fullPath = try std.mem.concat(allocator, u8, &slices);
            defer allocator.free(fullPath);

            exe.addCSourceFile(.{ .file = .{ .path = fullPath }, 
                                .flags = &.{"-std=c++11"} });
        }
    }

    exe.linkSystemLibrary("c++");

    const run_cmd = b.addRunArtifact(exe);
    const run_step = b.step("run", "Run zig_snake");
    run_step.dependOn(&run_cmd.step);

    b.installArtifact(exe);
}

