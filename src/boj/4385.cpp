#include <iostream>

using namespace std;

int reg[10], mem[1000];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    for (int x, i = 0; cin >> x; ) {
        mem[i++] = x;
    }

    bool halt = false;
    int pc = 0, timer = 0, opcode, i1, i2;
    while (!halt) {
        opcode = mem[pc];
        i2 = opcode % 10; opcode /= 10;
        i1 = opcode % 10; opcode /= 10;

        timer++, pc = (pc + 1) % 1000;

        switch (opcode) {
            case 1:
                halt = true;
                break;
            case 2:
                reg[i1] = i2;
                break;
            case 3:
                reg[i1] = (reg[i1] + i2) % 1000;
                break;
            case 4:
                reg[i1] = (reg[i1] * i2) % 1000;
                break;
            case 5:
                reg[i1] = reg[i2];
                break;
            case 6:
                reg[i1] = (reg[i1] + reg[i2]) % 1000;
                break;
            case 7:
                reg[i1] = (reg[i1] * reg[i2]) % 1000;
                break;
            case 8:
                reg[i1] = mem[reg[i2]];
                break;
            case 9:
                mem[reg[i2]] = reg[i1];
                break;
            case 0:
                if (reg[i2]) pc = reg[i1];
                break;
        }
    }

    cout << timer;

    return 0;
}
