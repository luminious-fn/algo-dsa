const my_heading= document.querySelector('h1');
my_heading.textContent= 'Hello world!';
let food= 'fruit1'

let myHTML= document.querySelector('h1');
myHTML.onclick= function() {
    alert('stop clicking');
}

let myImage= document.querySelector('img')
myImage.onclick= function() {
    myImage.setAttribute('src', 'images/firefox-icon.png')
}

let myButton= document.querySelector('button')
let myHeading= document.querySelector('h1')

function setUserName(){
    let myName= prompt('Please enter ur name')
    localStorage.setItem('name', myName)
    myHeading.textContent= 'mozilla is cool ' + myName
}

let userName = localStorage.getItem('name')
if (!userName){
    setUserName()
} else {
    myHeading.textContent = userName
}

//setUserName()