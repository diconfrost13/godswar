import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI172 , Script.Quest.QI173 , Script.Quest.QI174 , Script.Quest.QI175 , Script.Quest.QI176 , Script.Quest.QI177 , Script.Quest.QI178

def GetQuestReward():
  return Script.Quest.QR172 , Script.Quest.QR173 , Script.Quest.QR174 , Script.Quest.QR175 , Script.Quest.QR176 , Script.Quest.QR177 , Script.Quest.QR178


def Talk( player ):
# print "talk to Sparta_040"
  return "Sparta_040"

