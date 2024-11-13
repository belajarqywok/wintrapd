import sys

text = sys.argv[1]
shift = int(sys.argv[2])
feature = sys.argv[3]

alpha = [chr(i) for i in range(ord('a'), ord('z') + 1)]

def enc(plain, shift):
	result = ""
	for c in plain:
		for x, y in enumerate(alpha):
			if c == y:
				result += alpha[(x + shift) % 26]
		if c not in alpha:
			result += " "
	return result

def dec(plain, shift):
	result = ""
	for c in plain:
		for x, y in enumerate(alpha):
			if c == y:
				result += alpha[(x - shift) % 26]
		if c not in alpha:
			result += " "
	return result

def textnum(text):
	result = ""
	for c in text:
		for x, y in enumerate(alpha):
			if c == y :
				result += f"{x} "
		if c not in alpha:
			result += "| "
	return result

if feature == "enc":
	resf = enc(text, shift)
	print(f"Shift: {shift}")
	print(f"Plain: {text}")
	print(f"Num: {textnum(text)}\n")
	print(f"Cipher: {resf}")
	print(f"Num: {textnum(resf)}\n\n\n\n\n")
elif feature == "dec":
	resf = dec(text, shift)
	print(f"Shift: {shift}")
	print(f"Cipher: {text}")
	print(f"Num: {textnum(text)}\n")
	print(f"Plain: {resf}")
	print(f"Num: {textnum(resf)}\n\n\n\n\n")
elif feature == "brute":
	print(f"Shift: {shift}")
	print(f"Cipher: {text}\n")
	print("[ Brute Force ]\n")
	for i in range(shift + 1):
		resf = dec(text, i)
		print(f"[ Shift: {i} ] Plain -> {resf}")

