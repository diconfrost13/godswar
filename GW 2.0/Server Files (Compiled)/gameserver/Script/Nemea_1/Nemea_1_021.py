import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)


def GetQuestReward():
  return Script.Quest.QR1171


def Talk( player ):
# print "talk to Nemea_1_021"
  return "Nemea_1_021"

