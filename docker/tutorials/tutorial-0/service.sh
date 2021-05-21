mkdir -p $(pwd)/html
echo "Web server running: YES" > $(pwd)/html/index.html
docker run -d -p 80:80 --name=my_web_server -v $(pwd)/html/:/usr/share/nginx/html nginx
curl http://localhost:80
