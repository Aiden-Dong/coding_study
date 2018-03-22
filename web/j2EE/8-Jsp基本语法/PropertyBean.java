package bean;

public class PropertyBean {
	
	private String name;
	private int age;
	private double bhigh;
	private double bweight;
	
	public PropertyBean(){
		name = "noName";
		age = 0;
		bhigh = 0;
		bweight = 0;
	}
	
	public void setName(String name){
		if(name == null){
			this.name = "noName";
		}else{
			this.name = name;
		}
	}
	public String getName(){
		return this.name;
	}
	
	public void setAge(int age){
		this.age = age;
	}
	public int getAge(){
		return this.age;
	}
	
	public void setHigh(double bhigh){
		this.bhigh=bhigh;
	}
	public double getHigh(){
		return this.bhigh;
	}
	
	public void setBweight(double bweight){
		this.bweight = bweight;
	}
	public double getBweight(){
		return this.bweight;
	}
	public double getSum(){
		return (this.bhigh+this.bweight)/this.age;
	}
}
