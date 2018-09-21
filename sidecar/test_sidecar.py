import docker
import os 

import uuid
from pathlib import Path

id = str(uuid.uuid4())


#host directories
input_folder = os.path.join("/home/scu/input", id)
output_folder = os.path.join("/home/scu/output", id)
log_folder = os.path.join("/home/scu/log", id)

os.makedirs(input_folder)
os.makedirs(output_folder)
os.makedirs(log_folder)

log_file = os.path.join(log_folder, "log.dat")
Path(log_file).touch()

input_file = os.path.join(input_folder,"input")
with open(input_file, "w") as the_file:
    the_file.write("33")


client = docker.from_env(version='auto')
docker_image = "non-root-docker_car"

docker_env = { "INPUT_FOLDER" : input_folder, "OUTPUT_FOLDER" : output_folder, "LOG_FOLDER" : log_folder}

c=client.containers.run(docker_image, "run", detach=True, remove=True,
    volumes = { 'non-root-docker_input'  : {'bind' : '/home/scu/input'},
                'non-root-docker_output' : {'bind' : '/home/scu/output'},
                'non-root-docker_log'    : {'bind'  : '/home/scu/log'}},
               environment=docker_env)

for log in c.logs(stream=True):
    print(log)
