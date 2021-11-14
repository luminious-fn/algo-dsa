
firebaseConfig = {
    serviceAccount: "",
    databaseURL: "https://test-e3f20-default-rtdb.firebaseio.com/"
}

firebase.initializeApp(firebaseConfig);
let db = firebase.database();

function refresh_data() {
    let ref = db.ref("/customer_1krtgp/");
    ref.on('value', get_water_level)
    console.log('update request is made. wait for the response.')
}

let global_db = {}
function get_water_level(snapshot) {
    if (snapshot.exists()) {
        global_db = snapshot.val()
        console.log(global_db)
        console.log(global_db.device_id_1.provision.level)

        document.getElementById("tank_1_level_value").innerHTML = global_db.device_id_1.oper.present_level
        document.getElementById("tank_2_level_value").innerHTML = global_db.device_id_2.oper.present_level
        document.getElementById("tank_3_level_value").innerHTML = global_db.device_id_3.oper.present_level

        //document.getElementById("tank_1_level_value").innerHTML = global_db.device_id_1.provision.max_level
        //document.getElementById("tank_2_level_value").innerHTML = global_db.device_id_2.provision.max_level
        //document.getElementById("tank_3_level_value").innerHTML = global_db.device_id_3.provision.max_level


    } else {
        console.log('No data exists :err in dump')
    }
}
