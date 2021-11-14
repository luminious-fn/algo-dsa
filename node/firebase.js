function err_func(error) {
    if(error){
        console.log("Failed with error :" + error)
    } else {
        console.log('success!!!')
    }
}

firebaseConfig = {
    serviceAccount: "",
    databaseURL: "https://test-e3f20-default-rtdb.firebaseio.com/"
}

function dump(snapshot) {
    if (snapshot.exists()) {
        console.log(snapshot.val());
    } else {
        console.log('No data exists :err in dump')
    }
}

// ****************************************************************
let firebase = require("firebase");
firebase.initializeApp(firebaseConfig);
let db = firebase.database();

let ref = db.ref("/device_prov_1/");
ref.on('value', dump)

data = { 'info' : { lattitude:15.75, longitude:75.65, } }
ref.set(data, err_func);//overwrite

ref = db.ref("/device_prov_1/info/");
let data1 = {'customer': 'kurtakoti gp'}
ref.update(data1, err_func);// just update

ref = db.ref("/device_prov_1/");
let key = ref.child().key()
//let key = ref.key()
//console.log(key)


/*
ref = db.ref("/device_prov_2");
data = { 'info' : { lattitude:15.75, longitude:75.65, } }
ref.set(data, err_func);//overwrite

ref = db.ref("device_prov_3");
data = { 'info' : { lattitude:15.75, longitude:75.65, } }
ref.set(data, err_func);//overwrite
*/

//ref.once('value').then(dump)
//ref.once('value', dump) // read from local cache
//ref.get().then(dump) // read from local cache
//console.log('get done')

//ref.push();

//ref.update(data);//overwrite

/*
let playersRef = ref.child("players");
let playersKey = playersRef.key();
console.log(playersKey);


function act1(data, prevChildKey) {
    let newPlayer = data.val();
    console.log("name: " + newPlayer.name);
}

function child_changed(data) {
    let player = data.val();
    console.log('childe changed')
    console.log(player);
 }

ref.on("child_changed", child_changed)
ref.on("child_added", act1);
*/

/*
ref.once("value", function(snapshot) {
    var data = snapshot.val();
    console.log(data);
});
*/

//console.log(firebase)
console.log(' end ')
//process.exit()
//console.log("DEBUG", (new Error().stack.split("at ")[1]).trim());


