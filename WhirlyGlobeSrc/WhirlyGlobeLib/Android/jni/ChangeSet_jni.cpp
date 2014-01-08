#import <jni.h>
#import "handle.h"
#import "com_mousebirdconsulting_maply_ChangeSet.h"
#import "WhirlyGlobe.h"

using namespace WhirlyKit;

JNIEXPORT void JNICALL Java_com_mousebirdconsulting_maply_ChangeSet_initialise
  (JNIEnv *env, jobject obj)
{
	try
	{
		ChangeSet *changeSet = new ChangeSet();
		setHandle(env,obj,changeSet);
	}
	catch (...)
	{
		__android_log_print(ANDROID_LOG_VERBOSE, "Maply", "Crash in ChangeSet::initialise()");
	}
}

JNIEXPORT void JNICALL Java_com_mousebirdconsulting_maply_ChangeSet_dispose
  (JNIEnv *env, jobject obj)
{
	try
	{
		ChangeSet *changeSet = getHandle<ChangeSet>(env,obj);
		if (!changeSet)
			return;

		// Be sure to delete the contents
		for (unsigned int ii=0;ii<changeSet->size();ii++)
			delete changeSet->at(ii);

		delete changeSet;

		clearHandle(env,obj);
	}
	catch (...)
	{
		__android_log_print(ANDROID_LOG_VERBOSE, "Maply", "Crash in VectorObject::dispose()");
	}
}
