import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_VENDOR)



def GetitemListType():
  return 3 , 4 , 5 , 6

def GetItemList():
  return Script.Item.ItemList303 , Script.Item.ItemList313 , Script.Item.ItemList323 , Script.Item.ItemList333

def Talk( player ):
# print "talk to Parnitha_1_011"
  return "Parnitha_1_011"

