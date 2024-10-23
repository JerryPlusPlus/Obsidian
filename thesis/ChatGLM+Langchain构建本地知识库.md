1）创建环境，克隆ChatGLM仓库

```python
conda create --name langchain python=3.10
conda activate langchain[all]
conda install conda install pytorch torchvision torchaudio pytorch-cuda=11.8 -c pytorch -c nvidia
conda install transformers
pip install langchain[all]

cd ChatGLM-6B
pip install -r requirements.txt
```
下载模型和测试：

```python
from transformers import AutoTokenizer,AutoModel
tokenizer=AutoTokenizer.from_pretrained("THUDM/chatglm-6b",trust_remote_code=True)
model=AutoModel.from_pretrained("THUDM/chatglm-6b",trust_remote_code=True).quantize(4).half().cuda()

model=model.eval()
response,history=model.chat(tokenizer,"你好",history=[])
print("你好的回答：",response)

response,history=model.chat(tokenizer,"晚上睡不着应该怎么办",history=history)
print("晚上睡不着怎么办的回答：",response)
```

2）Langchain加载ChatGLM

```python
python api.py  #使用的是ChatGLM-6B下的api.py文件
```



```python
from langchain_community.llms.chatglm import ChatGLM

endpoint_url="http://127.0.0.1:8000"
llm=ChatGLM(
    endpoint_url=endpoint_url,
    max_tokens=8000,
    top_p=0.9,
)
```

3)文档向量化
```python 
pip install unstructured
pip install python-magic-bin==0.4.14
pip install sentence-transformers
pip install chromadb

```


