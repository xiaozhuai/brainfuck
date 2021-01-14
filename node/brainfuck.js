const fs = require('fs');
const putchar = (c) => process.stdout.write(String.fromCharCode(c));
const getchar = () => { let buffer = Buffer.alloc(1); fs.readSync(0, buffer, 0, 1); return buffer[0]; };
if (process.argv.length !== 3) {
    console.log(`Usage: node brainfuck.js <file.bf>`);
    process.exit(1);
}
const script = fs.readFileSync(process.argv[2], 'utf-8');
let memory = new Int8Array(1024 * 1024);
let ptr = 0;
let pair = 0;
for (let pc = 0; pc < script.length; ++pc) {
    switch (script.charAt(pc)) {
        case '>': ++ptr; break;
        case '<': --ptr; break;
        case '+': ++memory[ptr]; break;
        case '-': --memory[ptr]; break;
        case '.': putchar(memory[ptr]); break;
        case ',': memory[ptr] = getchar(); break;
        case '[':
            for (pair = 0; !memory[ptr] && pc < script.length; ++pc) {
                if (script.charAt(pc) === ']' && (!--pair)) { break; }
                else if (script.charAt(pc) === '[') { ++pair; }
            }
            if (pair) { console.log(`Expected character ']'`); process.exit(1); }
            break;
        case ']':
            for (pair = 0; pc >= 0; --pc) {
                if (script.charAt(pc) === '[' && (!--pair)) { --pc; break; }
                else if (script.charAt(pc) === ']') { ++pair; }
            }
            if (pair) { console.log(`Unexpected character ']'`); process.exit(1); }
            break;
        case ' ': case '\t': case '\r': case '\n': break;
        default: console.log(`Unexpected character '${script.charAt(pc)}'`); process.exit(1);
    }
}
