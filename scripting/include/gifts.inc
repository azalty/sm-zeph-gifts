#if defined _gifts_included
  #endinput
#endif
#define _gifts_included

public SharedPlugin:__pl_gifts = 
{
	name = "gifts",
	file = "gifts.smx",
#if defined REQUIRE_PLUGIN
	required = 1
#else
	required = 0
#endif
};

#if !defined REQUIRE_PLUGIN
public __pl_gifts_SetNTVOptional()
{
	MarkNativeAsOptional("Gifts_RegisterPlugin");
	MarkNativeAsOptional("Gifts_RemovePlugin");
	MarkNativeAsOptional("Gifts_SetClientCondition");
	MarkNativeAsOptional("Gifts_GetClientCondition");
	MarkNativeAsOptional("Gifts_SpawnGift");
}
#endif

enum GiftConditions
{
	Condition_None = 0,
	Condition_InCondition,
	Condition_InConditionCanPickUp
}

/**
 * Registers a listener with the gifts plugin.
 *
 * @param callback  The callback function
 * @return        True if plugin was successfully registered.
 */
native Gifts_RegisterPlugin(Function:callback);
native Gifts_RemovePlugin();
native Gifts_SetClientCondition(client, GiftConditions:clientState);
native Gifts_GetClientCondition(client);
native Gifts_SpawnGift(Function:callback, const String:model[], Float:lifetime, Float:position[3], data, owner=0);

forward Gifts_OnGiftSpawned(entity);

/**
 * Called when a client tries to grab a gift.
 *
 * @param client	The client index.
 * @param entity	The gift entity index.
 * @return			Return Plugin_Handled to block the grabbing & Plugin_Continue to let the client grab.
 *					If any plugin returns Plugin_Handled, the client won't be able to grab.
 */
forward Action Gifts_OnClientGrabGift(int client, int entity);