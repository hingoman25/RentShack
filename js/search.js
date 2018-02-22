'use strict';


var itemList = document.getElementById("itemList");


function snapshotToArray(snapshot) {
    var returnArr = [];

    snapshot.forEach(function(childSnapshot) {
        var item = childSnapshot.val();
        item.key = childSnapshot.key;

        returnArr.push(item);
    });

    return returnArr;
}

firebase.database().ref('/posts').on('value', function(snapshot) {
    var arr = snapshotToArray(snapshot);

    itemList.innerHTML = "";
    arr.forEach(function(e){
    	var pid = e.pid;
    	itemList.innerHTML += 
		   '<a style="text-decoration: none" style="display:block" href="../itemPage/itemPage.html?pid=' + pid + '">' +
					'<option>' + e.titlePost + '</option>' +
			'</a>';

    });
});

// "../itemPage/itemPage.html?pid=' + pid + '"