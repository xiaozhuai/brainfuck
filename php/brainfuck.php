<?php
if ($argc !== 2) {
    echo("Usage: php brainfuck.php <file.bf>\n");
    exit(1);
}
$script = file_get_contents($argv[1]);
$memory = array_fill(0, 1024 * 1024, 0);
$ptr = 0;
$pair = 0;
$size = strlen($script);
for($pc = 0; $pc < $size; ++$pc) {
    switch($script[$pc]) {
        case ">": ++$ptr; break;
        case "<": --$ptr; break;
        case "+": ++$memory[$ptr]; break;
        case "-": --$memory[$ptr]; break;
        case ".": echo(chr($memory[$ptr])); break;
        case ",": $memory[$ptr] = ord(fgetc(STDIN)); break;
        case "[":
            for ($pair = 0; !$memory[$ptr] && $pc < $size; ++$pc) {
                if ($script[$pc] === ']' && (!--$pair)) { break; }
                else if ($script[$pc] === '[') { ++$pair; }
            }
            if ($pair) { echo("Expected character ']'\n"); exit(1); }
            break;
        case "]":
            for ($pair = 0; $pc >= 0; --$pc) {
                if ($script[$pc] === '[' && (!--$pair)) { --$pc; break; }
                else if ($script[$pc] === ']') { ++$pair; }
            }
            if ($pair) { echo("Unexpected character ']'\n"); exit(1); }
            break;
        case " ": case "\t": case "\r": case "\n": break;
        default: echo("Unexpected character '${script[$pc]}'\n"); exit(1);
    }
}
