<h1>GreenTech</h1>

<h2>Status de toute les salles</h2>

{#await fetchDataSalle()}
  <p>loading</p>
{:then datas}
    <div class='display'>
        {#each datas as data}
            <div class='cardSalle'>
                <h3>{data.salle}</h3>
                <p>La pression est de {data.pression} Hpa</p>
                <p>L'humidité est de {data.humidity} %</p>
                <p>La qualité de l'air est {data.airQuality}</p>
                <p>La température est de {data.temperature} °C</p>
            </div>
        {/each}
    </div>
{:catch error}
  <p style="color: red">{error.message}</p>
{/await}

<h2>Status de tous le matériels</h2>

{#await fetchDataPosition()}
  <p>loading</p>
{:then datas}
    <div class='display'>
        {#each datas as data}
            <div class='cardSalle'>
                <h3>{data.material}</h3>
                <p>Il se situe {data.position}</p>
            </div>
        {/each}
    </div>
{:catch error}
  <p style="color: red">{error.message}</p>
{/await}

<script>
    async function fetchDataSalle() {
        const res = await fetch("http://localhost:8001/status");
        const data = await res.json();

        if (res.ok) {
            console.log(data)
            return data;
        } else {
            throw new Error(data);
        }
    }

    async function fetchDataPosition() {
        const res = await fetch("http://localhost:8001/position");
        const data = await res.json();

        if (res.ok) {
            console.log(data)
            return data;
        } else {
            throw new Error(data);
        }
    }
</script>

<style>
    .display {
        display: grid;
        grid-template-columns: 1fr 1fr 1fr;
        grid-gap: 25px;
        margin: 5%;
    }

    .cardSalle {
        text-align: center;
        background-color: #333333;
        border-radius: 25px;
        color: #F6F6F6;
    }
</style>