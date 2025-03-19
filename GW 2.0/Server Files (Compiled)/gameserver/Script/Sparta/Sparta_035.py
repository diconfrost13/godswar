import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_VENDOR)



def GetitemListType():
  return 1 , 2

def GetItemList():
  return Script.Item.ItemList102 , Script.Item.ItemList112

def Talk( player ):
# print "talk to Sparta_035"
  return "Sparta_035"

