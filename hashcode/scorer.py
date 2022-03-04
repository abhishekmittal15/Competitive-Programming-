import sys


from collections import defaultdict


class Contributor:
    def __init__(self, name) -> None:
        self.skills = defaultdict(int)
        self.name = name
        self.free_when = 0

    def addSkill(self, name, level) -> None:
        self.skills[name] = level

    def __repr__(self):
        print(self.name, self.skills)
        return ""


class Project:
    def __init__(self, name, duration, score, best_before):
        self.name = name
        self.duration = duration
        self.score = score
        self.best_before = best_before
        self.roles = {}

    def addRole(self, skill_name, level):
        self.roles[skill_name] = level

    def __repr__(self):
        print(
            self.name, self.duration, self.score, self.best_before, self.roles
        )
        return ""

fg = None
def take_input():
    return fg.readline().split()

def parser():
    num_collabs, num_projects = map(int, take_input())
    contributors = []
    projects = []
    for _ in range(num_collabs):
        name, num_skills = take_input()
        num_skills = int(num_skills)
        contrib = Contributor(name)
        for _ in range(num_skills):
            skill_name, level = take_input()
            level = int(level)
            contrib.addSkill(skill_name, level)
        contributors.append(contrib)

    for _ in range(num_projects):
        project_name, days, score, best_before, num_roles = take_input()
        days, score, best_before, num_roles = map(
            int, (days, score, best_before, num_roles)
        )
        project = Project(project_name, days, score, best_before)

        for _ in range(num_roles):
            skill_name, req_level = take_input()
            req_level = int(req_level)
            project.addRole(skill_name, req_level)

        projects.append(project)
    
    return contributors, projects

# 1. skills satisfied
# 2. score based on days
# 3. developers available

def scorer(inp,out):
    global fg
    fg = open(inp, 'r')
    contributors, projects = parser()
    contributor_dict = {}
    project_dict = {}
    for c in contributors:
        contributor_dict[c.name] = c
    for p in projects:
        project_dict[p.name] = p
    
    score = 0
    with open(out) as f:
        projects_planned=int(f.readline())
        for _ in range(projects_planned):
            project_name=f.readline().strip("\n")
            worker_names=f.readline().strip("\n").split(" ")
            if project_name not in project_dict.keys():
                print("wrong project name")
                exit()
            project = project_dict[project_name]
            workers = []
            for w in worker_names:
                if w not in contributor_dict.keys():
                    print("wrong worker name")
                    exit()
                workers.append(contributor_dict[w])
            # print(project)
            # print(workers)
            
            idx = 0
            for skill, level in project.roles.items():
                # print(skill)
                worker = workers[idx]
                # print(worker)
                if worker.skills[skill] < level - 1:
                    # print(project.name, skill, level, worker.name, worker.skills)
                    print("skills don't match")
                    exit()
                if worker.skills[skill] > level:
                    idx += 1
                    continue
                # find other helper
                found = False
                for w in workers:
                    if w.skills[skill] >= level:
                        found = True
                if not found:
                    print("Not found")
                    exit()
                worker.skills[skill] += 1
                idx += 1
            
            # finding start date of project
            date = 0
            for worker in workers:
                date = max(date, worker.free_when)

            date_end = date + project.duration
            if date_end >= project.best_before:
                score += max(0, project.score - (date_end - project.best_before))
            else:
                score += project.score

            # updating free_when
            for worker in workers:
                worker.free_when = date + project.duration
    return score
        




    #     line=f.readline() # Reading number of projects and contributors
    #     line=line.split(" ")
    #     n=int(line[0])
    #     m=int(line[1])
    #     num_collabs, num_projects = n, m

    #     contributors = []
    #     projects = []
    #     for _ in range(num_collabs):
    #         line = f.readline().split(" ")
    #         name, num_skills = line[0], int(line[1])
    #         num_skills = int(num_skills)
    #         contrib = Contributor(name)
    #         for _ in range(num_skills):
    #             skill_name, level = input().split()
    #             level = int(level)
    #             contrib.addSkill(skill_name, level)
    #         contributors.append(contrib)

    #     contributors={}
    #     projects={}

    #     # Now we will read the contributors 
    #     for _ in range(n):
    #         line=f.readline()
    #         line=line.split(" ")
    #         # contributor={
    #         #     "name":line[0],
    #         # }
    #         name=line[0]
    #         contributors[name]={}
    #         num_skills=int(line[1])
    #         # print(contributor["name"],num_skills)
    #         for _ in range(num_skills):
    #             skill=f.readline()
    #             skill=skill.split(" ")
    #             level=int(skill[1])
    #             skill=skill[0]
    #             contributors[name][skill]=level
    #             contributors[name]["dw"]=0
    #         # contributors.append(contributor)
    #     print(contributors)

    #     # Now we will read the projects 
    #     for _ in range(m):
    #         line=f.readline()
    #         line=line.split(" ")
    #         name=line[0]
    #         projects[name]={
    #             "d":int(line[1]),
    #             "s":int(line[2]),
    #             "b":int(line[3]),
    #             "r":int(line[4])
    #         }
    #         skills={}
    #         for _ in range(projects[name]["r"]):
    #             line=f.readline()
    #             line=line.split(" ")
    #             skills[line[0]]=int(line[1])
    #         projects[name]["skills"]=skills
    #     print(projects)

    # score=0
    # days_finished=0

    # with open(out) as f:
    #     projects_planned=int(f.readline())
    #     for _ in range(projects_planned):
    #         project_name=f.readline().strip("\n")
    #         workers=f.readline().strip("\n").split(" ")
    #         print(project_name,contributors)
    #         # best_before=projects[project_name]["b"]
    #         # project_score=projects[project_name]["s"]
    #         # if(days_finished<best_before):
    #         #     score+=project_score
    #         # else:
    #         #     score+=max(0,(project_score-days_finished+best_before))
    #         for contributor,skill in zip(workers,projects[project_name]["skills"].keys()):
    #             required_skill=projects[project_name]["skills"][skill]
    #             current_skill=contributors[contributor][skill]
    #             if(required_skill>current_skill+1):
    #                 print(f"{contributor} doesnt have enough skill for {project_name}")
    #                 exit()
    #             if(required_skill==current_skill+1):
    #                 # find any other contributor which has equal or higher skill 

    #             if(required_skill==current_skill):
    #                 # find 

        

    # return score
    
def main():
    n=len(sys.argv)
    input_file=sys.argv[1]
    output_file=sys.argv[2]
    print(scorer(input_file,output_file))

if __name__=="__main__":
    main()