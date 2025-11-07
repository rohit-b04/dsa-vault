class FooBar {
private:
    int n;
    mutex mtx;
    condition_variable cv;
    bool isFooPrinted = false;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> printfoo(mtx);
            cv.wait(printfoo, [this]{return !isFooPrinted;});
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            isFooPrinted = true;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> printbar(mtx);
            cv.wait(printbar, [this]{return isFooPrinted;});
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            isFooPrinted = false;
            cv.notify_all();
        }
    }
};