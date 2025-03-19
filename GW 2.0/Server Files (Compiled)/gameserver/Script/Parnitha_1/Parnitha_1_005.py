import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER)

def GetQuest():
  return Script.Quest.QI1171



def Talk( player ):
# print "talk to Parnitha_1_005"
  return "Parnitha_1_005"

