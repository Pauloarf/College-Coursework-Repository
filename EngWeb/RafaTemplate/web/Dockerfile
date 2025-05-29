FROM node:22.13.1

WORKDIR /app

RUN npm install -g pnpm

COPY dist /app
COPY package.json pnpm-lock.yaml ./
RUN pnpm install

# COPY . .

EXPOSE 16000
CMD ["pnpm", "run:service"]
# CMD apt update && apt upgrade -y && apt install -y net-tools iputils-ping telnet && sleep 999999
