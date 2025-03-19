import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI1172 , Script.Quest.QI1173 , Script.Quest.QI1174 , Script.Quest.QI1175 , Script.Quest.QI1176 , Script.Quest.QI1177 , Script.Quest.QI1178

def GetQuestReward():
  return Script.Quest.QR1172 , Script.Quest.QR1173 , Script.Quest.QR1174 , Script.Quest.QR1175 , Script.Quest.QR1176 , Script.Quest.QR1177 , Script.Quest.QR1178


def Talk( player ):
# print "talk to Athens_039"
  return "Athens_039"

