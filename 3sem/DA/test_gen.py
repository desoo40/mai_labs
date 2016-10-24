import random
import string

if __name__ == '__main__':
	for x in xrange(0, 10):
		pass
	action = random.choice("+-k")

	if action == '+':
		
		def generate_key():
			random.choice(string.letters)