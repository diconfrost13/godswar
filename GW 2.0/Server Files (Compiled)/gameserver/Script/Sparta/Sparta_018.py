import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER)

def GetQuest():
  return Script.Quest.QI140 , Script.Quest.QI150



def Talk( player ):
# print "talk to Sparta_018"
  return "Sparta_018"

