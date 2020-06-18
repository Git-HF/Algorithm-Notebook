import json
import os
import os.path as osp
import numpy as np

def H36FolderName(subject_id, act_id, subact_id, camera_id):
        return "s_%02d_act_%02d_subact_%02d_ca_%02d" % \
               (subject_id, act_id, subact_id, camera_id)

def H36ImageName(folder_name, frame_id):
        return "%s_%06d.jpg" % (folder_name, frame_id + 1)

annotations_dir = "D:/my_source/IntergralHumanPoseRegression/data/Human36M/annotations"
data_dir = "D:/my_source/IntergralHumanPoseRegression/data/Human36M/data"


def check():
    pass
"""
with open(osp.join(annotations_dir, "Human36M_subject1_data.json"),'r') as file_data, open(osp.join(annotations_dir, "Human36M_subject1_joint_3d.json")) as file_joint_3d:
    load_dict = json.load(file_data)
    load_dict_2 = json.load(file_joint_3d)
"""

subject_idx = (1, 5, 6, 7, 8, 9, 11)
action_idx = (2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16)
subaction_idx = (1, 2)
camera_idx = (1, 2, 3, 4)



for cur_subject_idx in subject_idx:

    json_camera = osp.join(annotations_dir, "Human36M_subject%d_camera.json" % (cur_subject_idx))
    json_data = osp.join(annotations_dir, "Human36M_subject%d_data.json" % (cur_subject_idx))
    json_3d_joint = osp.join(annotations_dir, "Human36M_subject%d_joint_3d.json" % (cur_subject_idx))

    with open(json_3d_joint, "r") as file_3d_joint, open(json_camera, "r") as file_camera, open(json_data, "r") as file_data:
        dic_3d_joint = json.load(file_3d_joint)
        dic_camera = json.load(file_camera)
        dic_data = json.load(file_data)

        index = 0
        for cur_action_idx in action_idx:
            for cur_subaction_idx in subaction_idx:

                for cur_camera_idx in camera_idx:
                    # cur_camera_idx = 0
                    floder_name = H36FolderName(cur_subject_idx, cur_action_idx, cur_subaction_idx, cur_camera_idx)

                    # 该文件夹下没有文件
                    if floder_name == "s_11_act_02_subact_02_ca_01":
                        continue
                    # os.listdir(path)列出指定文件夹下文件或者文件夹的列表
                    # num_floder表示相应文件夹下图片的数量
                    num_floder = len(os.listdir(osp.join(data_dir, floder_name)))

                    start_image_name = H36ImageName(floder_name, 0)
                    end_image_name = H36ImageName(floder_name, num_floder - 1)

                    # abcde = dic_data[index]
                    if(start_image_name != dic_data["images"][index]["file_name"].split("/")[1]):
                        print("start_image_name error: ", start_image_name, end="\n")
                        exit();
                    if(end_image_name != dic_data["images"][index+num_floder-1]["file_name"].split("/")[1]):
                        print("end_image_name error: ", end_image_name, end="\n")
                        exit();

                    dic_new = {}
                    list_joint_world = []
                    list_heights = []
                    list_widths = []
                    for cur_index in range(num_floder):
                        tmp_index = index + cur_index
                        list_joint_world.append(dic_3d_joint[str(cur_action_idx)][str(cur_subaction_idx)][str(cur_index)])
                        list_heights.append(dic_data["images"][tmp_index]["height"])
                        list_widths.append(dic_data["images"][tmp_index]["width"])

                    index += num_floder;

                    dic_new["joint_world"] = list_joint_world
                    dic_new["height"] = list_heights
                    dic_new["widths"] = list_widths

                    dic_new["R"] = dic_camera[str(cur_camera_idx)]["R"]
                    dic_new["t"] = dic_camera[str(cur_camera_idx)]["t"]
                    dic_new["f"] = dic_camera[str(cur_camera_idx)]["f"]
                    dic_new["c"] = dic_camera[str(cur_camera_idx)]["c"]

                    json_string = json.dumps(dic_new)
                    with open(osp.join(data_dir, floder_name, "meta.json"), "w") as save_file:
                        save_file.write(json_string)
                    
                    print("subject: %02d, action: %2d, subacton: %d, camera: %d" %(cur_subject_idx, cur_action_idx, cur_subaction_idx, cur_camera_idx))