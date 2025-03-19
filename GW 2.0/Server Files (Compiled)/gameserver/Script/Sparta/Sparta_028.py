import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_VENDOR)



def GetitemListType():
  return 3 , 4 , 5 , 6

def GetItemList():
  return Script.Item.ItemList201 , Script.Item.ItemList211 , Script.Item.ItemList221 , Script.Item.ItemList231

def Talk( player ):
# print "talk to Sparta_028"
  return "Sparta_028"

