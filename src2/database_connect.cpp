#include "firebase_cpp_sdk/include/firebase/database.h"


int main(){

	::firebase::AppOptions appOptions = ::firebase::AppOptions();

	appOptions.::firebase::AppOptions::set_app_id("rentshack-d2f8f");

	::firebase::App *app = ::firebase::App::Create(::firebase::AppOptions());

	//::firebase::App* app = ::firebase::App::Create(appOptions);

	//app -> ::firebase::AppOptions::set_app_id("rentshack-d2f8f");

	::firebase::database::Database *database = ::firebase::database::Database::GetInstance(app);

	// Get the root reference location of the database.
	firebase::database::DatabaseReference dbRef = database->GetReference();

	firebase::Future<firebase::database::DataSnapshot> result =
	    dbRef.GetReference().GetValue();

	return 0;

}