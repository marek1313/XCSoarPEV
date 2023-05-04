package com.felhr.usbserial;

import java.io.EOFException;

final class Buffer {
    private byte[] data = null;
    private int head = 0, tail = 0;

    public void write(byte[] src) {
        if (head == tail)
            head = tail = 0;

        if (data == null || tail + src.length > data.length) {
            byte[] old = data;

            int capacity = size() + src.length;
            if (capacity < 16384)
                capacity = 16384;
            data = new byte[capacity];
            if (size() > 0)
                System.arraycopy(old, head, data, 0, size());
            tail -= head;
            head = 0;
        }

        System.arraycopy(src, 0, data, tail, src.length);
        tail += src.length;
    }

    public int size() {
        return tail - head;
    }

    public byte[] readByteArray(int nbytes) throws EOFException {
        if (nbytes > size())
            throw new EOFException();

        byte[] result = new byte[nbytes];
        if (result.length > 0)
            System.arraycopy(data, head, result, 0, nbytes);
        head += nbytes;
        return result;
    }

    public byte[] readByteArray() {
        byte[] result = new byte[size()];
        if (result.length > 0)
            System.arraycopy(data, head, result, 0, result.length);
        head = tail = 0;
        return result;
    }
}
