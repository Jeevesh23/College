# Knowledge_base = {
#     "COVID": [
#         "Fever",
#         "Cough",
#         "Shortness of breath",
#         "Fatigue",
#         "Muscle aches",
#         "Headache",
#         "Loss of taste or smell",
#         "Sore throat",
#         "Congestion",
#         "Nausea or vomiting",
#         "Diarrhea",
#     ],
#     "Bronchitis": [
#         "Persistent cough",
#         "Cough that produces mucus",
#         "Shortness of breath",
#         "Wheezing",
#         "Chest discomfort",
#         "Fatigue",
#         "Fever",
#     ],
#     "Strep Throat": [
#         "Sore throat",
#         "Difficulty swallowing",
#         "Fever",
#         "Swollen tonsils and lymph nodes",
#         "Tiny red spots on the roof of the mouth",
#         "Rash",
#         "Nausea or vomiting",
#     ],
# }


# def Inference_Engine(symptoms):
#     chance = {}

#     for disease in Knowledge_base:
#         occurrence = 0
#         # For each disease in knowledge base check if symptoms are match
#         for symptom in Knowledge_base[disease]:
#             occurrence += 1 if symptom in symptoms else 0
#         chance[disease] = occurrence / len(Knowledge_base[disease])

#     guess = (
#         [
#             disease
#             for disease in Knowledge_base
#             if chance[disease] == max(chance.values())
#         ]
#         if max(chance.values()) > 0
#         else []
#     )
#     print()
#     Explanation_Module(guess, chance)


# def Explanation_Module(guess, chance):
#     if len(guess) == 0:
#         print("You have no disease according to us.")
#     elif len(guess) > 1:
#         print("We are confused between the following diseases.")
#         for disease_guess in guess:
#             print(f"{disease_guess}")
#     elif chance[guess[0]] == 1:
#         print(f"You definitely have {guess[0]} disease.")
#     else:
#         print(f"You may have {guess[0]} disease with probability {chance[guess[0]]} .")


# def UI():
#     symptoms = []
#     questions = []

#     # Add diseases symptoms to questions list
#     for disease in Knowledge_base:
#         questions.extend(Knowledge_base[disease])
#     # Remove repeating symptoms among diseases
#     questions = list(set(questions))

#     print("Hello user! We will now evaluate your case.")
#     for question in questions:
#         reply = input(f"Do you have \033[1m{question}\033[0m as a symptom?[y/N]:")
#         if reply.upper() == "Y":
#             symptoms.append(question)

#     Inference_Engine(symptoms)


# if __name__ == "__main__":
#     UI()


def health_diagnostic():
    print("Welcome to the Health Diagnostic System!")
    potential_diseases = []

    # Ask questions based on the knowledge base
    print("Do you have a fever?")
    fever = input("Enter 'yes' or 'no': ").lower()
    if fever == "yes":
        print("Do you have a cough?")
        cough = input("Enter 'yes' or 'no': ").lower()
        if cough == "yes":
            print("Do you have shortness of breath?")
            breathlessness = input("Enter 'yes' or 'no': ").lower()
            if breathlessness == "yes":
                potential_diseases.append("COVID-19")
            else:
                print("Do you have chest pain or discomfort?")
                chest_pain = input("Enter 'yes' or 'no': ").lower()
                if chest_pain == "yes":
                    potential_diseases.append("Bronchitis")
                else:
                    print("Do you have fatigue or body aches?")
                    fatigue = input("Enter 'yes' or 'no': ").lower()
                    if fatigue == "yes":
                        potential_diseases.append("COVID-19")
                    else:
                        print("Do you have headache or confusion?")
                        confusion = input("Enter 'yes' or 'no': ").lower()
                        if confusion == "yes":
                            potential_diseases.append("COVID-19")
                        else:
                            print("Do you have sore throat or runny nose?")
                            throat_nose_symptoms = input(
                                "Enter 'yes' or 'no': "
                            ).lower()
                            if throat_nose_symptoms == "yes":
                                potential_diseases.append("COVID-19")
                            else:
                                potential_diseases.append("COVID-19")
        else:
            print("Do you have muscle aches or fatigue?")
            muscle_aches = input("Enter 'yes' or 'no': ").lower()
            if muscle_aches == "yes":
                potential_diseases.append("COVID-19")
            else:
                print("Do you have sore throat or runny nose?")
                throat_nose_symptoms = input("Enter 'yes' or 'no': ").lower()
                if throat_nose_symptoms == "yes":
                    potential_diseases.append("Common Cold")
                else:
                    potential_diseases.append("COVID-19")
    else:
        print("Do you have a sore throat?")
        sore_throat = input("Enter 'yes' or 'no': ").lower()
        if sore_throat == "yes":
            print("Do you have swollen glands in your neck?")
            swollen_glands = input("Enter 'yes' or 'no': ").lower()
            if swollen_glands == "yes":
                potential_diseases.append("Strep Throat")
            else:
                print("Do you have white patches on your tonsils?")
                white_patches = input("Enter 'yes' or 'no': ").lower()
                if white_patches == "yes":
                    potential_diseases.append("Strep Throat")
                else:
                    potential_diseases.append("Sore Throat")
        else:
            print("Do you have chest congestion or wheezing?")
            chest_congestion = input("Enter 'yes' or 'no': ").lower()
            if chest_congestion == "yes":
                potential_diseases.append("Bronchitis")
            else:
                print("Do you have body aches or joint pain?")
                body_joint_pain = input("Enter 'yes' or 'no': ").lower()
                if body_joint_pain == "yes":
                    potential_diseases.append("COVID-19")
                else:
                    print("Do you have difficulty swallowing or loss of appetite?")
                    swallowing_difficulty = input("Enter 'yes' or 'no': ").lower()
                    if swallowing_difficulty == "yes":
                        potential_diseases.append("Strep Throat")
                    else:
                        potential_diseases.append("No specific disease")

    # Print potential diseases
    if potential_diseases:
        print("Based on your symptoms, potential diseases may include:")
        for disease in potential_diseases:
            print("- " + disease)
    else:
        print("No potential diseases found based on your symptoms.")


# Call the function to start the diagnostic process
health_diagnostic()
