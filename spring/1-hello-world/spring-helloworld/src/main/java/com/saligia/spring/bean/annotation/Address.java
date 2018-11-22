package com.saligia.spring.bean.annotation;

import org.springframework.beans.factory.annotation.Value;

public class Address {
    private String address = null;

    public Address(String address) {
        this.address = address;
    }

    @Override
    public String toString() {
        return address;
    }
}
