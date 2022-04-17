def func(**kwargs):
    # kwargs = 사전형
    # kwargs.items() 사용 x
    keys = kwargs.keys()
    values = kwargs.values()
    for key in keys:
        print(f'key : {key}, val : {kwargs[key]}')
    print("==============================")
    for key, val in zip(keys,values):
        print(f'key : {key}, val : {val}')
    print("==============================")
    for key, val in kwargs.items():
        print(f'key : {key}, val : {val}')

func(a=10, b=20)