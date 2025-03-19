import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI1204 , Script.Quest.QI1205 , Script.Quest.QI1206

def GetQuestReward():
  return Script.Quest.QR1150 , Script.Quest.QR1204 , Script.Quest.QR1205 , Script.Quest.QR1206 , Script.Quest.QR1223 , Script.Quest.QR1224 , Script.Quest.QR1225 , Script.Quest.QR1226


def Talk( player ):
# print "talk to Megara_All_005"
  return "Megara_All_005"

