function checkAnswer() {
  // Get the user's answer
  let answer = document.getElementById("answer").value;

  // Check if the answer is a number and not negative
  if (isNaN(answer)) 
  {
    document.getElementById("result").innerHTML = "You must enter a number and not a string.";
  }
  else if(answer < 0)
  {
    document.getElementById("result").innerHTML = "You must enter a positive number.";
  }
  else 
  {
    // Calculate the force
    let mass = 0.8;
    let acceleration = 10;
    let force = mass * acceleration;

    // Check if the answer is correct
    if (answer == force) {
      document.getElementById("result").innerHTML = "You are correct!";
    } else {
      document.getElementById("result").innerHTML = "You are wrong."
    }
  }
}
