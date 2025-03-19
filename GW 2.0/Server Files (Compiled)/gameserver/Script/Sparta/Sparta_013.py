import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER)

def GetQuest():
  return Script.Quest.QI107



def Talk( player ):
# print "talk to Sparta_013"
  return "Sparta_013"

