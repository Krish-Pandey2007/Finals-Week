import subprocess
import os
import sys

print("Python stress engine")

if os.name!="nt":
    exe_prefix="./"
else:
    exe_prefix=""

binaries = {
    "optimal": "optimal.cpp",
    "brute": "brute.cpp",
    "gen_small": "gen_small.cpp"
}

for exe , src in binaries.items():
    subprocess.run(["g++", "-O3", src, "-o", exe])

print("Compilation successful, proceeding to stress testing")

test_case=1

while True:
    with open("input.txt","w") as f_in:
        subprocess.run([exe_prefix+"gen_small",str(test_case)],stdout=f_in)
    
    with open("optimal_out.txt","w") as f_opt, open("input.txt","r") as f_in:
        subprocess.run([exe_prefix+"optimal"],stdin=f_in,stdout=f_opt)

    with open("brute_out.txt","w") as f_brute, open("input.txt","r") as f_in:
        subprocess.run([exe_prefix+"brute"],stdin=f_in,stdout=f_brute)

    with open("optimal_out.txt","r") as f_opt, open("brute_out.txt","r") as f_brute:
        opt_output=f_opt.read().strip()
        brute_output=f_brute.read().strip()

    if(opt_output==brute_output):
        print("Test case "+str(test_case)+" passed")
    else:
        print()
        print("MISMATCH BETWEEN BRUTE FORCE AND OPTIMAL ON TEST CASE: "+str(test_case))
        print()

        print("INPUT")
        with open("input.txt","r") as f_in:
            print(f_in.read())

        print("BRUTE FORCE OUTPUT:")
        print(brute_output)

        print("OPTIMAL APPROACH OUTPUT:")
        print(opt_output)
        break

    test_case+=1
    


