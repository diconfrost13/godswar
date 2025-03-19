import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER)

def GetQuest():
  return Script.Quest.QI1123 , Script.Quest.QI1124 , Script.Quest.QI1125 , Script.Quest.QI1126 , Script.Quest.QI1127 , Script.Quest.QI1129 , Script.Quest.QI1130 , Script.Quest.QI1131 , Script.Quest.QI1132 , Script.Quest.QI1133



def Talk( player ):
# print "talk to Athens_016"
  return "Athens_016"

