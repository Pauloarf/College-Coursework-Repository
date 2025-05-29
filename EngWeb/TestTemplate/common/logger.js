const colors = {
    reset: "\x1b[0m",
    white: "\x1b[37m",
    red: "\x1b[31m",
    yellow: "\x1b[33m",
    green: "\x1b[32m",
};

function getTimestamp() {
    const now = new Date();
    const yyyy = now.getFullYear();
    const mm = String(now.getMonth() + 1).padStart(2, '0');
    const dd = String(now.getDate()).padStart(2, '0');
    const h = String(now.getHours()).padStart(2, '0');
    const m = String(now.getMinutes()).padStart(2, '0');
    const s = String(now.getSeconds()).padStart(2, '0');
    return `${yyyy}/${mm}/${dd} - ${h}h:${m}m:${s}s`;
}

const logger = {
    info(text) {
        console.log(`${colors.white}[INFO][${getTimestamp()}] - ${text}${colors.reset}`);
    },
    warn(text) {
        console.warn(`${colors.yellow}[WARN][${getTimestamp()}] - ${text}${colors.reset}`);
    },
    error(text) {
        console.error(`${colors.red}[ERROR][${getTimestamp()}] - ${text}${colors.reset}`);
    },
    success(text) {
        console.log(`${colors.green}[SUCCESS][${getTimestamp()}] - ${text}${colors.reset}`);
    },
};

module.exports = logger;
