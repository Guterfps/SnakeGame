// raylib-zig (c) Nikolas Wipper 2023

const rl = @import("raylib");
const game = @cImport({
    @cInclude("bindings.h");
    });

pub fn main() anyerror!void {

    game.PlayGame();
    
}
