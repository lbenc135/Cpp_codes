import random
import subprocess

MAXX = 16000
MAXY = 9000
VISIBILITY = 2200
SPEED = 800
SPEEDG = 400
RANGE = 1760

class Ghost:
	id=0
	x=0; y=0
	state=0; value=0
	
	def __init__(self, mid, coorx, coory):
		id=mid; x=coorx; y=coory

class Buster:
	id=0
	x=0; y=0
	state=0; value=-1
	
	def __init__(self, mid, coorx, coory):
		id=mid; x=coorx; y=coory

class Entity:
	id=0
	x=0
	y=0
	type=0
	state=0
	value=0
	
	def __init__(self, mid, mx, my, mtype, mstate, mvalue):
		id=mid; x=mx; y=my; type=mtype; state=mstate; value=mvalue
	
	
ghosts = []
busters = []

ghostStamina = [3, 15, 40];

bustersPerPlayer = random.randint(2, 4)
ghostCount = random.randint(8, 28)
myTeamId = random.randint(0, 1)

def dist(x1, y1, x2, y2):
	return sqrt(pow(x1-x2, 2)+pow(y1-y2, 2))



for i in range(0, ghostCount):
	x=0
	y=0
	while ((x<3000 and y<3000) or (x>MAXX-3000 and y>MAXY-3000)):
		x=random.randint(0, MAXX)
		y=random.randint(0, MAXY)
	ghosts.append(Ghost(i, x, y))


if(bustersPerPlayer==2):
	busters.insert(0, Buster(0, 2024, 1176))
	busters.insert(1, Buster(1, 1176, 2024))
elif(bustersPerPlayer==3):
	busters.insert(0, Buster(0, 1600, 1600))
	busters.insert(1, Buster(1, 2449, 751))
	busters.insert(2, Buster(2, 751, 2449))
elif(bustersPerPlayer==4):
	busters.insert(0, Buster(0, 327, 2873))
	busters.insert(1, Buster(1, 1176, 2024))
	busters.insert(2, Buster(2, 2024, 1176))
	busters.insert(3, Buster(3, 2873, 327))

for i in range(0, bustersPerPlayer):
	busters.insert(i+bustersPerPlayer, Buster(i+bustersPerPlayer, MAXX-busters[i], MAXY-busters[i]))



ai1 = subprocess.Popen("ai.exe", stdin=subprocess.PIPE, stdout=subprocess.PIPE)
ai1in = ai1.stdin; ai1out = ai1.stdout
ai2 = subprocess.Popen("ai.exe", stdin=subprocess.PIPE, stdout=subprocess.PIPE)
ai2in = ai2.stdin; ai2out = ai2.stdout

ai1in.write(str(bustersPerPlayer) + ' ' + str(ghostCount) + " 0\n");
ai2in.write(str(bustersPerPlayer) + ' ' + str(ghostCount) + " 1\n");

turn = 400
score1 = 0; score2 = 0
while (turn):
	turn = turn-1
	
	entities = []
	
	# send inputs to ais
	# data 2 ai1
	for i in range(bustersPerPlayer, 2*bustersPerPlayer):
		for j in range(0, bustersPerPlayer):
			if(dist(busters[i].x, busters[i].y, busters[j].x, busters[j].y)<=2200):
				entities.append(Entity(busters[i].id, busters[i].x, busters[i].y, 1, busters[i].state, busters[i].value))
				
				
	for i in range(0, ghostCount):
		for j in range(0, bustersPerPlayer):
			if(dist(ghosts[i].x, ghosts[i].y, busters[j].x, busters[j].y)<=2200):
				entities.append(Entity(ghosts[i].id, ghosts[i].x, ghosts[i].y, -1, ghosts[i].state, ghosts[i].value))
				
	for e in entities:
		ai1in.write(str(len(entities))+'\n');
		ai1in.write(str(e.id)+' '+str(e.x)+' '+str(e.y)+' '+str(e.type)+' '+str(e.state)+' '+str(e.value)+'\n');
	
	# data 2 ai2
	entities2 = []
	for i in range(0, bustersPerPlayer):
		for j in range(bustersPerPlayer, 2*bustersPerPlayer):
			if(dist(busters[i].x, busters[i].y, busters[j].x, busters[j].y)<=2200):
				entities2.append(Entity(busters[i].id, busters[i].x, busters[i].y, 0, busters[i].state, busters[i].value))
				
				
	for i in range(0, ghostCount):
		for j in range(bustersPerPlayer, 2*bustersPerPlayer):
			if(dist(ghosts[i].x, ghosts[i].y, busters[j].x, busters[j].y)<=2200):
				entities2.append(Entity(ghosts[i].id, ghosts[i].x, ghosts[i].y, -1, ghosts[i].state, ghosts[i].value))
				
	for e in entities2:
		ai2in.write(str(len(entities2))+'\n');
		ai2in.write(str(e.id)+' '+str(e.x)+' '+str(e.y)+' '+str(e.type)+' '+str(e.state)+' '+str(e.value)+'\n');
	
	
		
	
	for i in range(0, bustersPerPlayer):
		response = ai1out.readline()
		data = response.split()
		if(data[0]=="MOVE"):
			k = atan((data[2]-busters[i].y)/(data[1]-busters[i].x))
			busters[i].x = busters[i].x + sin(k)*800;
			busters[i].y = busters[i].y + cos(k)*800;
		elif(data[0]=="BUST"):
			tdist = dist(busters[i].x, busters[i].y, ghosts[data[1]].x, ghosts[data[1]].y)
			if(tdist>=900 and tdist<=1760):
				if(ghosts[data[1]].state==0):
					
	
	