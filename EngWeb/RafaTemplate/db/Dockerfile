FROM mongo:latest

# Create a volume for MongoDB data
VOLUME /data/db

# Copy dataset into the container
COPY ./dataset/db.json /tmp/db.json 

# Run MongoDB
COPY startup.sh /startup.sh
RUN chmod +x /startup.sh
CMD ["/startup.sh"]