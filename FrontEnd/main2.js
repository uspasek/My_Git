class Animal{

  constructor(name, height, weight){

    this.name =  name;
    this.height = height;
    this.weight = weight;
  }

  nameLength(){
    return this.name.length;
  }

}

class Dog extends Animal{

  constructor(name, height, weight, barkVolume, leashColor){
    super(name, height, weight);
    console.log("Created animal", name,
                "with the height of ", height,
                "cm and the weight ", weight,
                "kg", barkVolume,
                "barkVolume", leashColor,
                "leashColor");
    this.barkVolume = barkVolume;
    this.leashColor = leashColor
  }

  bark(){
    if(this.barkVolume > 50){
      console.log(this.name, " barks loud: ", this.barkVolume);
    }
    else{
      console.log(this.name, " barks timidly: ", this.barkVolume);
    }

  }

}

var bigDog =  new Dog("Tinka", 50, 60, 79, "blue");
var smallDog =  new Dog("Tinka", 12, 34, 21, "blue");
bigDog.bark();


if(bigDog.barkVolume > smallDog.barkVolume){
  console.log("the great dog is huge");
}else{
    console.log("What is wrong");
}
