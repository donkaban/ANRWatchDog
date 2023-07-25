package com.github.anrwatchdog;

public class ANRGenerator {
    private final Object _mutex = new Object();
    public static void Sleep() {
        try {
            Thread.sleep(8 * 1000);
        }
        catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    public static void InfiniteLoop() {
        int i = 0;
        //noinspection InfiniteLoopStatement
        while (true) {
            i++;
        }
    }

    public class LockerThread extends Thread {

        LockerThread() {
            setName("APP: Locker");
        }

        @Override
        public void run() {
            synchronized (_mutex) {
                //noinspection InfiniteLoopStatement
                while (true)
                    Sleep();
            }
        }
    }
}