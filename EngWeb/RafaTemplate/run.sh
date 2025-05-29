#!/bin/bash

#####################################################################################
# run.sh
# Automatic Docker Compose container manager.
# Allows for granular control over which containers to start and basic environment configuration.
# 
# Version: 1.0.0
# Author: DarkenLM
#####################################################################################

# Container names
DB_NAME=mongo
WEB_NAME=web
API_NAME=api

# Options
DB_ENABLED=true
WEB_ENABLED=true
API_ENABLED=true
DB_STARTUP_SCRIPT=false

# Process arguments
for arg in "$@"; do
  case $arg in
    --no-db)
      DB_ENABLED=false
      shift
      ;;
    --db-prep)
      DB_STARTUP_SCRIPT=true
      shift
      ;;
    --no-web)
      WEB_ENABLED=false
      shift
      ;;
    --no-api)
      API_ENABLED=false
      shift
      ;;
    *)
      OTHER_ARGS+=("$arg")
      ;;
  esac
done

# Build the docker-compose command
COMPOSE_CMD="docker compose up --build"

# Process options
if [ "$DB_ENABLED" == "true" ]; then
  COMPOSE_CMD="$COMPOSE_CMD $DB_NAME"
fi

if [ "$WEB_ENABLED" == "true" ]; then
  COMPOSE_CMD="$COMPOSE_CMD $WEB_NAME"
fi

if [ "$API_ENABLED" == "true" ]; then
  COMPOSE_CMD="$COMPOSE_CMD $API_NAME"
fi

if [ "$DB_STARTUP_SCRIPT" == "true" ]; then
  echo Enable startup
  export RUN_DB_STARTUP_SCRIPT="true"
fi

# Compose final command
COMPOSE_CMD="$COMPOSE_CMD ${OTHER_ARGS[*]}"

echo $RUN_DB_STARTUP_SCRIPT

# Execute the command
echo "Running: $COMPOSE_CMD"
RUN_DB_STARTUP_SCRIPT=$RUN_DB_STARTUP_SCRIPT eval $COMPOSE_CMD
