import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER)

def GetQuest():
  return Script.Quest.QI1140 , Script.Quest.QI1150



def Talk( player ):
# print "talk to Athens_018"
  return "Athens_018"

