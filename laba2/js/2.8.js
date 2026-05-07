const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question("Введите количество встреч: ", (n) => {
    n = parseInt(n);
    let meetings = [];
    let i = 0;

    function askMeeting() {
        if (i === n) {
            meetings.sort((a, b) => a.end - b.end);

            let result = [];
            let lastEnd = -1;

            for (let m of meetings) {
                if (m.start >= lastEnd) {
                    lastEnd = m.end;
                    result.push(m.id);
                }
            }

            console.log("Количество:", result.length);
            console.log("Номера:", result.join(" "));
            rl.close();
            return;
        }

        rl.question(`Введите время начала и окончания каждой встречи (формат: start end): `, (line) => {
            let [start, end] = line.split(' ').map(Number);
            meetings.push({ start, end, id: i + 1 });
            i++;
            askMeeting();
        });
    }

    askMeeting();
});