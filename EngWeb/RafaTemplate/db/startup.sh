#!/bin/bash
mongod --bind_ip_all &

if [ "$RUN_DB_STARTUP_SCRIPT" == "true" ]; then
    sleep 5
    echo "Running startup script."
    # mongoimport -d contratos -c contratos --type=csv --fieldFile=/tmp/fields.txt --ignoreBlanks --parseGrace skipRow /tmp/db.csv
    # mongoimport -d contratos -c contratos --type=csv --headerline --ignoreBlanks --parseGrace skipRow /tmp/db.csv
    mongoimport -d contratos -c contratos /tmp/db.json --jsonArray
else
    echo "Skipping startup script."
fi

wait
