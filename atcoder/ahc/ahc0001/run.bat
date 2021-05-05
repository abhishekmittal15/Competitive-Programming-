@echo off
cmd /C ".\a.exe<inp.txt>out.txt"
python test.py
python tester.py