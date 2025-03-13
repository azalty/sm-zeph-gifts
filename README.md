# sm-zeph-gifts
Modified/patched version of the "Gifts!" sourcemod plugin by Zephyrus

https://forums.alliedmods.net/showthread.php?p=2777945#post2777945

## Notes
Modified the plugin for my private needs, but here it is.
Includes some changes and fixes:

**Version 3.1 by azalty** (from 2.3 by Zephyrus):

- added a collision fix: prop_dynamic_override is now used instead of prop_physics_override, and collisions are now manually set. You can now set the collision box (square) in the config file.
```
// Size of the gift collision box in hammer/csgo units.
// -
// Default: "20"
sm_gifts_size "20"
```
20 means a box of 20x20 units

- added the default gift model for csgo (same as css)

- fixed a bug with the saving of the gift's position

- fixed gifts being duplicated (can't remember the details to be honest)

- added a forward: Gifts_OnClientGrabGift which passes the client and the entity indexes and allows you to block the event (the client won't be able to grab the gift if you return Plugin_Handled)
```
/**
 * Called when a client tries to grab a gift.
 *
 * @param client	The client index.
 * @param entity	The gift entity index.
 * @return			Return Plugin_Handled to block the grabbing & Plugin_Continue to let the client grab.
 *					If any plugin returns Plugin_Handled, the client won't be able to grab.
 */
forward Action Gifts_OnClientGrabGift(int client, int entity);
```


These fixes won't be useful to everyone, I know, but since there is a small chance that someone might need this, I'll post the plugin.

Plugin compiled with **SM 1.7** (I think) - it doesn't compile on SM 1.10 but will work fine on a SM 1.10 and + server

---

I decided to post this here as it was only on the AlliedModders forum. It's now also on GitHub :)
