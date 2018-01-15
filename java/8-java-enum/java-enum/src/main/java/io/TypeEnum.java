package io;

/**
 * Created by saligia on 17-8-15.
 */
public enum TypeEnum {
    READ(10),
    WRITE(11),
    EXEC(13);

    private int numVals;

    TypeEnum(int numVals){
        this.numVals = numVals;
    }

    public int getFlag(){
        return this.numVals;
    }

}