import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI50 , Script.Quest.QI53 , Script.Quest.QI198 , Script.Quest.QI199 , Script.Quest.QI219 , Script.Quest.QI220 , Script.Quest.QI221 , Script.Quest.QI222

def GetQuestReward():
  return Script.Quest.QR49 , Script.Quest.QR52 , Script.Quest.QR198 , Script.Quest.QR199 , Script.Quest.QR217 , Script.Quest.QR218 , Script.Quest.QR219 , Script.Quest.QR220 , Script.Quest.QR221


def Talk( player ):
# print "talk to Peloponnese_All_002"
  return "Peloponnese_All_002"

