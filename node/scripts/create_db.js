function err_func(error) {
    if(error){
        console.log("Failed with error :" + error)
    } else {
        console.log('success!!!' + error)
    }
}

function dump(snapshot) {
    if (snapshot.exists()) {
        console.log(snapshot.val());
        console.log(snapshot.val().customer_1krtgp.device_id_1.provision.level);
    } else {
        console.log('No data exists :err in dump')
    }
}

function create_db() {
    firebaseConfig = {
        serviceAccount: "",
        databaseURL: "https://test-e3f20-default-rtdb.firebaseio.com/"
    }
    let firebase = require("firebase");
    firebase.initializeApp(firebaseConfig);
    let db = firebase.database();
    let ref = db.ref("/customer_bktgp/");
    ref = db.ref("/");
    data = {
        "customer_1krtgp" : {
            'device_id_1': {
                'device_type': 'water_tank_sensor',
                'provision': {
                    'max_level' : 5,
                    'motor_on_level' : 3,
                    'motor_off_level' : 5,
                    'subscribers': '8792796008 ',
                },
                'oper': {
                    'present_level' : 3,
                    'time_of_level_reach' : '2021-03-19 T 22:59:41'
                },
            },
            'device_id_2': {
                'device_type': 'water_tank_sensor',
                'provision': {
                    'max_level' : 6,
                },
                'oper': {
                    'present_level' : 3,
                    'time_of_level_reach' : '2021-03-19 T 22:59:41'
                },
            },
            'device_id_3': {
                'device_type': 'water_tank_sensor',
                'provision': {
                    'max_level' : 10,
                },
                'oper': {
                    'present_level' : 3,
                    'time_of_level_reach' : '2021-03-19 T 22:59:41'
                },
            },
            'device_id_4': {
                'device_type': 'astro',
                'provision': {
                    'max_level' : 15.75,
                }

            },
        },
/*
        "customer_bktgp" : {
            'device_id_5': {
                'device_type': 'astro',
                'provision': {
                    'lattitude' : 15.75,
                    'longitude' : 75.65,
                }
            },
            'device_id_6': {
                'device_type': 'astro',
                'provision': {
                    'lattitude' : 15.75,
                    'longitude' : 75.65,
                }
            },
            'device_id_7': {
                'device_type': 'water_tank_sensor',
                'provision': {
                    'max_level' : 5,
                }
            },
            'device_id_8': {
                'device_type': 'water_tank_sensor',
                'provision': {
                    'max_level' : 5,
                }
            },
        }, */

    }
    ref.set(data, err_func);//overwrite
    ref.on('value', dump)
    console.log('done')
}

create_db()
