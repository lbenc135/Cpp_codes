import subprocess

print "Started parent...\n"

process = subprocess.Popen("child.exe", stdin=subprocess.PIPE, stdout=subprocess.PIPE)
pin = process.stdin
pout = process.stdout

pin.write("Hello world\n");
pin.write(str(1) + ' ' + str(2) + '\n');
while True:
  line = pout.readline()
  if line != '':
	print line
  else:
    break