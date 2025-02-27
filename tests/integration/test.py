import subprocess

def test1():
    res=subprocess.run(["build/app.exe"], input="(2+2)*   2          -1                   ",text=True,capture_output=True)
    assert res.returncode == 0
    assert int(res.stdout) == 7

def test2():
    res=subprocess.run(["build/app.exe", "--float"], input=" (4 + 4 - 4     *4/4+44444)/10", text=True,capture_output=True)
    assert res.returncode == 0
    assert float(res.stdout) == 4444.8

def test3():
    res=subprocess.run(["build/app.exe", "--float"], input="1000000001 * 2",text=True,capture_output=True)
    assert res.returncode != 0

def test4():
    res=subprocess.run(["build/app.exe"], input="(((((((((((((((((((((((((((((9+1*((((((((((((((((((((((((((((((((((((((((9+2)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))",text=True,capture_output=True)
    assert res.returncode == 0
    assert int(res.stdout) == 20

def test5():
    res=subprocess.run(["build/app.exe", "--float"], input="1+-1",text=True,capture_output=True)
    assert res.returncode != 0

def test6():
    res=subprocess.run(["build/app.exe", "--float"], input="3+2)",text=True,capture_output=True)
    assert res.returncode != 0

def test7():
    res=subprocess.run(["build/app.exe", "--float"], input="((3+1)",text=True,capture_output=True)
    assert res.returncode != 0

def test8():
    res=subprocess.run(["build/app.exe", "--float"], input="1/0.0005",text=True,capture_output=True)
    assert res.returncode != 0

def test9():
    res=subprocess.run(["build/app.exe", "--float"], input="9999999999999999999999999999999+1",text=True,capture_output=True)
    assert res.returncode != 0

def test10():
    res=subprocess.run(["build/app.exe", "--float"], input="-1-1",text=True,capture_output=True)
    assert res.returncode != 0