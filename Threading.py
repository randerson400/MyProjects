from multiprocessing import Pool 
from threading import Thread 
from datetime import datetime  

class SquareGetter(Thread):
    def __init__(self, domain): 
        Thread.__init__(self) 
        self.domain = domain 

    def run(self): 
        self.ip = self.domain * self.domain 

def squared(n): 
    return n * n  

if __name__ == "__main__": 
    URLS = ['www.google.com', 'www.example.com', 'www.python.org', 'www.yahoo.com', 'www.ubc.ca', 'www.wikipedia.org'] 
    inputs = [ i for i in range(100) ]  

    t1 = datetime.now() 
    singleRes = [] 

    for i in inputs: 
        singleRes.append(i*i) 

    t2 = datetime.now() 
    print( "Using a single process it took:", (t2-t1).total_seconds() )  

    t1 = datetime.now() 
    pool = Pool(len(inputs)) 
    results = pool.map(squared, inputs) 
    t2 = datetime.now() 
    pool.close() 

    print( "Using multiprocessing it took:", (t2-t1).total_seconds() ) 

    print("-----------") 

    t1 = datetime.now() 
    threads = [] 

    for url in inputs: 
        t = SquareGetter(url) 
        t.start() 
        threads.append(t) 

    for t in threads: 
        t.join() 

    t2 = datetime.now() 

    print("Using multi-threading it took:", (t2-t1).total_seconds()) 